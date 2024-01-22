package com.convenient.record.rbxkslgwvj;

import android.content.ContentValues;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.text.Editable;
import android.text.InputType;
import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    private EditText searchEditText;
    private Button addNoteButton;
    private ListView noteListView;
    private ArrayAdapter<Note> noteAdapter;

    private ArrayList<Note> notes;
    private NoteDatabaseHelper databaseHelper;
    private EditText input;
    private ImageButton editButton;

    private boolean isEditMode = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        searchEditText = findViewById(R.id.searchEditText);
        addNoteButton = findViewById(R.id.addNoteButton);
        noteListView = findViewById(R.id.noteListView);
        editButton = findViewById(R.id.editButton);

        notes = new ArrayList<>();
        noteAdapter = new NoteAdapter(this, notes);
        noteListView.setAdapter(noteAdapter);

        databaseHelper = new NoteDatabaseHelper(this);
        loadNotes();

        noteListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                editNote(position);
            }
        });

        noteListView.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
                deleteNote(position);
                return true;
            }
        });

        searchEditText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {
            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                // 在文本变化时执行搜索逻辑
                searchNotes(charSequence.toString());
            }

            @Override
            public void afterTextChanged(Editable editable) {
            }
        });
    }

    private void loadNotes() {
        SQLiteDatabase db = databaseHelper.getReadableDatabase();
        notes.clear();

        Cursor cursor = db.query(NoteDatabaseHelper.TABLE_NAME, null, null, null, null, null, null);

        while (cursor.moveToNext()) {
            int idIndex = cursor.getColumnIndex(NoteDatabaseHelper.COLUMN_ID);
            int contentIndex = cursor.getColumnIndex(NoteDatabaseHelper.COLUMN_CONTENT);
            long id = cursor.getLong(idIndex);
            String content = cursor.getString(contentIndex);
            Note note = new Note(id, content);
            notes.add(note);
        }

        cursor.close();
        noteAdapter.notifyDataSetChanged();
    }

//    public void saveNote(View view) {
//        String noteContent = searchEditText.getText().toString().trim(); // 使用正确的 EditText，即编辑框
//
//        if (!noteContent.isEmpty()) {
//            SQLiteDatabase db = databaseHelper.getWritableDatabase();
//            long id = db.insert(NoteDatabaseHelper.TABLE_NAME, null, getContentValues(noteContent));
//
//            if (id != -1) {
//                Note newNote = new Note(id, noteContent);
//                notes.add(newNote);
//                noteAdapter.notifyDataSetChanged();
//
//                // 清空输入框
//                searchEditText.getText().clear();
//            } else {
//                Toast.makeText(this, "Failed to save note", Toast.LENGTH_SHORT).show();
//            }
//
//            db.close();
//        }
//    }



    private ContentValues getContentValues(String content) {
        ContentValues values = new ContentValues();
        values.put(NoteDatabaseHelper.COLUMN_CONTENT, content);
        return values;
    }

    public void addNote(View view) {
        if (isEditMode) {
            // 如果处于编辑模式，点击添加按钮会取消编辑模式
            isEditMode = false;
            // 清空输入框
            searchEditText.getText().clear();
        } else {
            // 处于非编辑模式，启动一个新的Activity或者弹出对话框以便用户输入新的Note内容
            // 这里使用 AlertDialog 来获取用户输入
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("Add Note");

            // 设置布局，包含一个 EditText 供用户输入
            final EditText input = new EditText(this);
            input.setInputType(InputType.TYPE_CLASS_TEXT);
            builder.setView(input);

            builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    String noteContent = input.getText().toString().trim();

                    if (!noteContent.isEmpty()) {
                        SQLiteDatabase db = databaseHelper.getWritableDatabase();
                        long id = db.insert(NoteDatabaseHelper.TABLE_NAME, null, getContentValues(noteContent));

                        if (id != -1) {
                            Note newNote = new Note(id, noteContent);
                            notes.add(newNote);
                            noteAdapter.notifyDataSetChanged();
                            Log.d("NoteApp", "Note added successfully: " + newNote.getContent());
                        } else {
                            Toast.makeText(MainActivity.this, "Failed to save note", Toast.LENGTH_SHORT).show();
                        }

                        db.close();
                    }
                }
            });

            builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.cancel();
                }
            });

            builder.show();
        }
    }


    private void editNote(final int position) {
        if (isEditMode) {
            final Note selectedNote = notes.get(position);

            // 创建带有EditText的AlertDialog，以允许用户编辑笔记内容
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setTitle("Edit Note");

            final EditText editInput = new EditText(this);
            editInput.setInputType(InputType.TYPE_CLASS_TEXT);
            editInput.setText(selectedNote.getContent());
            builder.setView(editInput);

            builder.setPositiveButton("Save", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    String editedContent = editInput.getText().toString().trim();

                    if (!editedContent.isEmpty()) {
                        // 将编辑后的内容保存到数据库
                        SQLiteDatabase db = databaseHelper.getWritableDatabase();
                        ContentValues values = getContentValues(editedContent);
                        db.update(
                                NoteDatabaseHelper.TABLE_NAME,
                                values,
                                NoteDatabaseHelper.COLUMN_ID + " = ?",
                                new String[]{String.valueOf(selectedNote.getId())}
                        );

                        // 更新列表中的笔记
                        selectedNote.setContent(editedContent);
                        noteAdapter.notifyDataSetChanged();
                        db.close();
                    } else {
                        Toast.makeText(MainActivity.this, "Note content cannot be empty", Toast.LENGTH_SHORT).show();
                    }
                }
            });

            builder.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.cancel();
                }
            });

            builder.show();
        } else {
            // 如果不是编辑模式，此处可以执行您在非编辑模式下的操作
        }
    }


    private void deleteNote(int position) {
        Note selectedNote = notes.get(position);
        deleteNoteFromDatabase(selectedNote.getId());
        notes.remove(position);
        noteAdapter.notifyDataSetChanged();
    }

    private void deleteNoteFromDatabase(long id) {
        SQLiteDatabase db = databaseHelper.getWritableDatabase();
        db.delete(NoteDatabaseHelper.TABLE_NAME, NoteDatabaseHelper.COLUMN_ID + " = ?", new String[]{String.valueOf(id)});
        db.close();
    }

    public void searchNotes(String query) {
        if (!query.isEmpty()) {
            // 根据搜索框中的查询内容执行相应的搜索逻辑
            // 这里只是一个简单的示例，你可能需要根据实际需求更新笔记列表显示匹配的笔记
            ArrayList<Note> filteredNotes = new ArrayList<>();
            for (Note note : notes) {
                if (note.getContent().toLowerCase().contains(query.toLowerCase())) {
                    filteredNotes.add(note);
                }
            }
            // 更新适配器和列表
            noteAdapter.clear();
            noteAdapter.addAll(filteredNotes);
            noteAdapter.notifyDataSetChanged();
        } else {
            // 如果查询内容为空，恢复显示所有笔记
            loadNotes();
        }
    }

    public void toggleEditMode(View view) {
        isEditMode = !isEditMode;

        // 根据编辑模式切换状态执行相应的逻辑
        if (isEditMode) {
            Toast.makeText(this, "Edit Mode On", Toast.LENGTH_SHORT).show();
            // 在这里添加进入编辑模式时的操作
            editButton.setImageResource(R.drawable.icon1); // 使用系统保存图标
        } else {
            Toast.makeText(this, "Edit Mode Off", Toast.LENGTH_SHORT).show();
            // 在这里添加退出编辑模式时的操作
            // 清空输入框
            searchEditText.getText().clear();
            editButton.setImageResource(R.drawable.icon2); // 使用系统编辑图标
        }
    }


}

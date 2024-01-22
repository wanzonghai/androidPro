package com.convenient.record.rbxkslgwvj;

public class Note {
    private String content;
    private long id;

    public Note(long id,String content) {
        this.id=id;
        this.content = content;
    }

    public String getContent() {
        return content;
    }
    // setter for content
    public void setContent(String content) {
        this.content = content;
    }
    public long getId() {
        return id;
    }
}

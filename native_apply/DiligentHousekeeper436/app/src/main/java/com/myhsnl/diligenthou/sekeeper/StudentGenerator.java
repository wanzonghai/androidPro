package com.myhsnl.diligenthou.sekeeper;

import com.myhsnl.diligenthou.model.Student;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class StudentGenerator {

    private static final String[] MALE_NAMES = {"John", "Michael", "Andrew", "David", "Matthew"};
    private static final String[] FEMALE_NAMES = {"Emily", "Jessica", "Sophia", "Olivia", "Emma"};
    private static final String[] LAST_NAMES = {"Smith", "Johnson", "Williams", "Jones", "Brown"};

    private static final String[] GENDER_TYPES = {"Male", "Female"};

    public static List<Student> generateRandomStudents(int count) {
        List<Student> students = new ArrayList<>();
        Random random = new Random();

        for (int i = 0; i < count; i++) {
            String firstName = getRandomName(random.nextBoolean());
            String lastName = LAST_NAMES[random.nextInt(LAST_NAMES.length)];
            String rollNumber = String.format("%010d", random.nextInt(1000000000) + 1);
            String genderType = GENDER_TYPES[random.nextInt(GENDER_TYPES.length)];
            String contactNumber = generateRandomContactNumber();

            students.add(new Student(firstName + " " + lastName, rollNumber, genderType, contactNumber));
        }

        return students;
    }

    private static String getRandomName(boolean isMale) {
        String[] names = isMale ? MALE_NAMES : FEMALE_NAMES;
        return names[new Random().nextInt(names.length)];
    }

    private static String generateRandomContactNumber() {
        Random random = new Random();
        StringBuilder contactNumber = new StringBuilder("+1-");

        for (int i = 0; i < 10; i++) {
            contactNumber.append(random.nextInt(10));
        }

        return contactNumber.toString();
    }
}

CREATE TABLE IF NOT EXISTS students (
    id int(11) PRIMARY KEY NOT NULL,
    name text NOT NULL
);

CREATE TABLE IF NOT EXISTS subjects (
    id int(11) PRIMARY KEY NOT NULL,
    name text NOT NULL
);

CREATE TABLE IF NOT EXISTS students_subjects (
    student_id int(11) NOT NULL,
    subject_id int(11) NOT NULL,
    PRIMARY KEY (student_id, subject_id),
    CONSTRAINT students_subjects_ibfk_1 FOREIGN KEY (student_id) REFERENCES students (id),
    CONSTRAINT students_subjects_ibfk_2 FOREIGN KEY (subject_id) REFERENCES subjects (id)
);

CREATE DATABASE IF NOT EXISTS university_exams;

USE university_exams;

CREATE TABLE IF NOT EXISTS exams(
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    inserted_at TIMESTAMP DEFAULT NOW(),
    name VARCHAR(100) NOT NULL,
    conducting_date TIMESTAMP,
    session_type ENUM('зимна', 'лятна') NOT NULL,
    average_score DECIMAL
);

CREATE TABLE IF NOT EXISTS subjects(
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    inserted_at TIMESTAMP DEFAULT NOW(),
    name VARCHAR(100) NOT NULL,
    introduction_date DATE NOT NULL
);

CREATE TABLE IF NOT EXISTS students(
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    inserted_at TIMESTAMP DEFAULT NOW(),
    first_name VARCHAR(50) NOT NULL,
    middle_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    faculty_number VARCHAR(9) UNIQUE NOT NULL,
    group_number SMALLINT,
    course_number ENUM('1', '2', '3', '4')
);

CREATE TABLE IF NOT EXISTS teachers(
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    inserted_at TIMESTAMP DEFAULT NOW(),
    first_name VARCHAR(50) NOT NULL,
    middle_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    subject_id BIGINT NOT NULL,
    CONSTRAINT FOREIGN KEY (subject_id) REFERENCES subjects(id)
);

CREATE TABLE IF NOT EXISTS students_exams(
    student_id BIGINT NOT NULL,
    exam_id BIGINT NOT NULL,
    inserted_at TIMESTAMP DEFAULT NOW(),
    CONSTRAINT FOREIGN KEY (student_id) REFERENCES students(id),
    CONSTRAINT FOREIGN KEY (exam_id) REFERENCES exams(id)
);

CREATE TABLE IF NOT EXISTS students_subjects(
    student_id BIGINT NOT NULL,
    subject_id BIGINT NOT NULL,
    inserted_at TIMESTAMP DEFAULT NOW(),
    CONSTRAINT FOREIGN KEY (student_id) REFERENCES students(id),
    CONSTRAINT FOREIGN KEY (subject_id) REFERENCES subjects(id)
);

CREATE TABLE IF NOT EXISTS exams_audit(
    id BIGINT PRIMARY KEY AUTO_INCREMENT,
    inserted_at TIMESTAMP DEFAULT NOW(),
    operation ENUM('INSERT', 'UPDATE', 'DELETE') NOT NULL,
    old_name VARCHAR(100) NOT NULL,
    new_name VARCHAR(100),
    old_conducting_date TIMESTAMP NOT NULL,
    new_conducting_date TIMESTAMP,
    old_session_type ENUM('зимна', 'лятна') NOT NULL,
    new_session_type ENUM('зимна', 'лятна'),
    old_average_score DECIMAL NOT NULL,
    new_average_score DECIMAL
);

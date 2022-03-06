CREATE TABLE IF NOT EXISTS  sports (
	id INT AUTO_INCREMENT PRIMARY KEY,
	name VARCHAR(50) NOT NULL
);

CREATE TABLE IF NOT EXISTS students (
	id INT AUTO_INCREMENT PRIMARY KEY,
	student_name VARCHAR(255) NOT NULL,
	egn VARCHAR(10) NOT NULL UNIQUE,
	phone_number VARCHAR(25) NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS coaches (
	id INT AUTO_INCREMENT PRIMARY KEY,
	name VARCHAR(50) NOT NULL,
	email VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS groups (
	id INT AUTO_INCREMENT PRIMARY KEY,
	day_of_week ENUM('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday'),
	hour_of_event TIMESTAMP,
	location VARCHAR(255) NOT NULL,
	sport_id INT NOT NULL,
	coach_id INT NOT NULL,
	CONSTRAINT FOREIGN KEY (sport_id) REFERENCES sports(id),
	CONSTRAINT FOREIGN KEY (coach_id) REFERENCES coaches(id),
	UNIQUE KEY (day_of_week, hour_of_event, location)
);

CREATE TABLE IF NOT EXISTS students_groups (
	student_id INT NOT NULL,
	group_id INT NOT NULL,
	CONSTRAINT FOREIGN KEY (student_id) REFERENCES students(id),
	CONSTRAINT FOREIGN KEY (group_id) REFERENCES groups(id),
	PRIMARY KEY ( student_id, group_id )
);

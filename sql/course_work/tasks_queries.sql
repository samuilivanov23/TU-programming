/* Task 1 */
select * from students where group_number=44;

/* Task 2 */
SELECT course_number, group_number, COUNT(*) AS students_count FROM students WHERE course_number=2 GROUP BY group_number;
SELECT course_number, group_number, COUNT(*) AS students_count FROM students WHERE course_number=2 GROUP BY group_number HAVING COUNT(*) > 10;

/* Task 3 */
SELECT * FROM students AS s JOIN students_exams AS se ON s.id=se.student_id JOIN exams AS e ON se.exam_id=e.id WHERE s.course_number=3 AND e.session_type='зимна';
SELECT * FROM students AS s LEFT JOIN students_exams AS se ON s.id=se.student_id LEFT JOIN exams AS e ON se.exam_id=e.id WHERE s.course_number=4;

/* Task 4 */
SELECT * FROM students AS s JOIN students_exams AS se ON s.id=se.student_id JOIN exams AS e ON se.exam_id=e.id GROUP BY s.group_number HAVING e.average_score=MAX(e.average_score);

/* Task 5 */


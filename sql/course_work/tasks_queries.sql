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
/* Stored Procedure */
DELIMITER |

CREATE PROCEDURE GetAllWinterExamsOfSpecificCourse(IN courseNumber CHAR(1))
BEGIN
    SELECT * FROM students AS s JOIN students_exams AS se ON s.id=se.student_id JOIN exams AS e ON se.exam_id=e.id WHERE s.course_number=courseNumber AND e.session_type='зимна';
END;
|
DELIMITER ;

SET @courseNumber='3';
CALL GetAllWinterExamsOfSpecificCourse( @courseNumber );

/* Trigger */
DELIMITER |

CREATE TRIGGER after_exams_update AFTER UPDATE ON exams 
FOR EACH ROW 
    BEGIN
        INSERT INTO exams_audit(operation, 
            old_name, 
            new_name, 
            old_conducting_date, 
            new_conducting_date, 
            old_session_type, 
            new_session_type, 
            old_average_score, 
            new_average_score) 
        VALUES ('UPDATE', 
            OLD.name, 
            CASE NEW.name WHEN OLD.name THEN NULL ELSE NEW.name END,
            OLD.conducting_date, 
            CASE NEW.conducting_date WHEN OLD.conducting_date THEN NULL ELSE NEW.conducting_date END, 
            OLD.session_type, 
            CASE NEW.session_type WHEN OLD.session_type THEN NULL ELSE NEW.session_type END, 
            OLD.average_score, 
            CASE NEW.average_score WHEN OLD.average_score THEN NULL ELSE NEW.average_score END); 
    END;
|

DELIMITER ;

/* Coursor */
DELIMITER |
CREATE PROCEDURE CursorTest()
BEGIN
        DECLARE finished INT;
        DECLARE tmpName VARCHAR(100);
        DECLARE tmpSessionType VARCHAR(5);
        DECLARE tmpAverageScore DECIMAL;
                        
        DECLARE ExamCursor CURSOR FOR
        SELECT name, session_type, average_score
        FROM exams where session_type='лятна';

        DECLARE CONTINUE handler FOR NOT FOUND SET finished = 1;
        SET finished = 0;
                                            
        OPEN ExamCursor;
        exam_loop: WHILE( finished = 0 )
        DO
            FETCH ExamCursor INTO tmpName, tmpSessionType, tmpAverageScore;
            IF( finished = 1 )
                THEN
                    LEAVE exam_loop;
                END IF;
                SELECT tmpName, tmpSessionType, tmpAverageScore;
        END WHILE;
        CLOSE ExamCursor;
        SET finished = 0;
        SELECT 'Finished!';
END;
|
DELIMITER ;

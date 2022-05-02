import MySQLdb, random
from dbconfig import dbname, dbuser, dbpassword, dbhost

def importData():
    try:
        connection = MySQLdb.connect(dbhost, dbuser, dbpassword, dbname)

        connection.autocommit = True
        cur = connection.cursor()
    except Exception as e:
        print(e)

    session_type = ['зимна', 'лятна']
    group_number = ['41', '42', '43', '44', '45']
    course_number = ['1', '2', '3', '4']
    
    try:
        for i in range(100, 300):
            #students
            sql = ('INSERT INTO students (first_name, middle_name, last_name, faculty_number, group_number, course_number) ' 
                    'VALUES(%s, %s, %s, %s, %s, %s)')
            
            cur.execute(sql, ("First_Name"+str(i), 
                              "Middle_Name"+str(i), 
                              "Last_Name"+str(i), 
                              "111111"+str(i), 
                              group_number[random.randint(0, 4)], 
                              course_number[random.randint(0, 3)]))
       
            #subjects
            sql = 'INSERT INTO subjects (name, introduction_date) ' 
                  'VALUES(%s, (SELECT CAST((TIMESTAMP("2013-04-30 14:53:27") - INTERVAL FLOOR( RAND( ) * 730) DAY) as DATE)))'
            
            cur.execute(sql, ("Name"+str(i),))

            #exams
            sql = 'INSERT INTO exams (name, conducting_date, session_type, average_score) '
                  'VALUES(%s, (SELECT TIMESTAMP("2013-04-30 14:53:27") - INTERVAL FLOOR( RAND( ) * 730) DAY), %s, %s)'
            
            cur.execute(sql, ("Name"+str(i), 
                              session_type[random.randint(0, 1)], 
                              random.randint(1, 100)))
        connection.commit()

        for i in range(100, 300):
            #teachers
            sql = 'INSERT INTO teachers (first_name, middle_name, last_name, subject_id) VALUES(%s, %s, %s, %s)'
            
            cur.execute(sql, ("First_Name"+str(i), "Middle_Name"+str(i), "Last_Name"+str(i), random.randint(1, 200)))    

            #students_exams
            sql = 'INSERT INTO students_exams (student_id, exam_id) VALUES(%s, %s)'

            cur.execute(sql, (random.randint(1, 200), random.randint(1, 200)))

            #students_subjects
            sql = 'INSERT INTO students_subjects (student_id, subject_id) VALUES(%s, %s)'
            
            cur.execute(sql, (random.randint(1, 200), random.randint(1, 200)))
        
        connection.commit()
    except Exception as e:
        print(e)

    try:
        cur.close()
        connection.close()
    except Exception as e:
        print(e)

if __name__ == '__main__':
    importData()

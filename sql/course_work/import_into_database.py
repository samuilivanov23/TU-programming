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

    for i in range(100, 300):
        sql = 'insert into students (first_name, middle_name, last_name, faculty_number, group_number, course_number) values(%s, %s, %s, %s, %s, %s)'
        cur.execute(sql, ("First_Name"+str(i), "Middle_Name"+str(i), "Last_Name"+str(i), "111111"+str(i), group_number[random.randint(0, 4)], course_number[random.randint(0, 3)]))
   
        sql = 'insert into subjects (name, introduction_date) values(%s, (SELECT cast((timestamp("2013-04-30 14:53:27") - INTERVAL FLOOR( RAND( ) * 730) DAY) as DATE)))'
        cur.execute(sql, ("Name"+str(i),))

        sql = 'insert into exams (name, conducting_date, session_type, average_score) values(%s, (SELECT timestamp("2013-04-30 14:53:27") - INTERVAL FLOOR( RAND( ) * 730) DAY), %s, %s)'
        cur.execute(sql, ("Name"+str(i), session_type[random.randint(0, 1)], random.randint(1, 100)))
    connection.commit()

    for i in range(100, 300):
        sql = 'insert into teachers (first_name, middle_name, last_name, subject_id) values(%s, %s, %s, %s)'
        cur.execute(sql, ("First_Name"+str(i), "Middle_Name"+str(i), "Last_Name"+str(i), random.randint(1, 200)))    

        sql = 'insert into students_exams (student_id, exam_id) values(%s, %s)'
        cur.execute(sql, (random.randint(1, 200), random.randint(1, 200)))

        sql = 'insert into students_subjects (student_id, subject_id) values(%s, %s)'
        cur.execute(sql, (random.randint(1, 200), random.randint(1, 200)))
    
    connection.commit()

    try:
        cur.close()
        connection.close()
    except Exception as e:
        print(e)

if __name__ == '__main__':
    importData()

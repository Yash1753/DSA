# Write your MySQL query statement below
SELECT s.student_id, s.student_name, sb.subject_name , COUNT(e.student_id) as attended_exams
FROM Students s
CROSS JOIN Subjects sb
left join Examinations e ON s.student_id = e.student_id and sb.subject_name = e.subject_name
GROUP by s.student_id, s.student_name, sb.subject_name
ORDER BY s.student_id, s.student_name, sb.subject_name
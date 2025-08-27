# Write your MySQL query statement below
#--e.id as unique_id, e.name as name

SELECT eu.unique_id, e.name FROM Employees e
LEFT JOIN EmployeeUNI eu ON e.id = eu.id


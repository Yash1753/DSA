# Write your MySQL query statement below
SELECT e.name
FROM 
Employee e
JOIN 
(SELECT managerId, COUNT(managerId) as cnt
from Employee
GROUP by managerId
HAVING cnt >=5 
)  d ON  e.id = d.managerId

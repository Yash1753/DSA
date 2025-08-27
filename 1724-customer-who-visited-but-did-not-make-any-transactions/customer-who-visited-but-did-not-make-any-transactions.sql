# Write your MySQL query statement below
# 
SELECT v.customer_id, COUNT(*) as count_no_trans
from Visits v
LEFT join Transactions t on v.visit_id = t.visit_id 
WHERE t.transaction_id is NULL
GROUP BY v.customer_id
ORDER BY count_no_trans DESC
#GROUP BY v.customer_id 
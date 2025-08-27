# Write your MySQL query statement below
# start end h same table se op dekhne h toh self join krdo

Select a1.machine_id, round(avg(a2.timestamp - a1.timestamp),3) as processing_time
From Activity a1
Join Activity a2 on   a1.machine_id = a2.machine_id 
and a1.process_id = a2.process_id
 and a1.activity_type='start' and a2.activity_type='end'
GROUP by a1.machine_id
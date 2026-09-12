# Write your MySQL query statement below
with temp as(
select num, LAG(num, 1) over (order by id) as pre1, LAG(num, 2) over (order by id) as pre2
from logs)

select distinct num as ConsecutiveNums 
from temp 
where num = pre1 and num = pre2;


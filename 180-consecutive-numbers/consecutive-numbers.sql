# Write your MySQL query statement below
select distinct(num) as ConsecutiveNums
from Logs l
where exists (
    select 1
    from logs l2
    where l.id+1= l2.id and l.num=l2.num
)
and exists (
    select 1
    from logs l3
    where l.id+2= l3.id and l.num=l3.num
)
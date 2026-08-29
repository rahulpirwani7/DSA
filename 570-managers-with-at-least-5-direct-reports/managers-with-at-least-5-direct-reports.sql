# Write your MySQL query statement below
select name
from Employee e1
where  5 <= (
    select count(*)
    from Employee e2
    where e2.managerId=e1.id
)
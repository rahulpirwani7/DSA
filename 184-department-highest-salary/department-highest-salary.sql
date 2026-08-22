# Write your MySQL query statement below
select d.name as Department,e.name as Employee, salary as Salary
from Employee e
inner join Department d
on e.departmentId=d.id
where salary=(
    select max(salary)
    from Employee e2
    where e2.departmentId=e.departmentId
)
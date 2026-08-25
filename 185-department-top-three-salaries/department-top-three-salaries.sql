# Write your MySQL query statement below
SELECT d.name as Department, e.name as Employee, e.salary as Salary
from Department d
inner join  Employee e
    on e.departmentId = d.id
where 3 > (
    select count(Distinct(e2.salary))
    from Employee e2
    where e2.salary > e.salary
        and e.departmentId = e2.departmentId
)
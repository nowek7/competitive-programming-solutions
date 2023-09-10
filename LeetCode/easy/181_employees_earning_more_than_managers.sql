# 181. Employees Earning More Than Their Managers
select
    name as Employee
from Employee
    inner join (
        select id, salary from Employee
    ) Manager on (managerId = Manager.id)
where
    Employee.salary > Manager.salary
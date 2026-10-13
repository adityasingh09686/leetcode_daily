-- Write your PostgreSQL query statement below

select 
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
FROM Employee e
JOIN Department d
    ON e.departmentId = d.id
WHERE (e.departmentId, e.salary) IN (
select departmentId ,max(salary) from employee
group by departmentId
);





















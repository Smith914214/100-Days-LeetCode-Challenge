# Write your MySQL query statement below
SELECT unique_id, name
FROM Employees
LEFT join EmployeeUNI
on Employees.id = EmployeeUNI.id;
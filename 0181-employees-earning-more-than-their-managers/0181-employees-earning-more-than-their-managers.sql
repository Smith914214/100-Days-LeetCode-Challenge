# Write your MySQL query statement below

-- Find employees who earn more than their managers
SELECT e1.name AS Employee

-- Join the Employee table with itself to match employees with their managers
FROM Employee e1
JOIN Employee e2
ON e1.managerId = e2.id

-- Keep only employees whose salary is greater than their manager's salary
WHERE e1.salary > e2.salary;
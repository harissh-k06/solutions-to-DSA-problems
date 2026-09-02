# Write your MySQL query statement below
SELECT emp.name , eu.unique_id  from 
Employees as emp LEFT JOIN EmployeeUNI as eu  on eu.id = emp.id;

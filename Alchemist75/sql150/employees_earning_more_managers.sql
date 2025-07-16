# Write your MySQL query statement below
SELECT e2.name AS Employee #no col in original table with this name so rename
FROM Employee e1
INNER JOIN Employee e2 #compare internaal values so use inner join
ON e1.id = e2.managerId #since emp with managerId are actually managers.So we are telling table that e1 are managers
WHERE e1.salary<e2.salary
/*
why e1 is managers ???Its because we need to match the number 3 and 4 within two different columns. In id column, 3 & 4 are assigned to Sam and Max whereas in managerId column, 3 & 4 are assigned to Joe and Henry. Therefore, e1 w.r.t id are Managers whereas e2 w.r.t managerId are Employee
*/
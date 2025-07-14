# Write your MySQL query statement below
SELECT email 
FROM person
GROUP BY email
HAVING COUNT(email) > 1;
#O(n) and O(n)
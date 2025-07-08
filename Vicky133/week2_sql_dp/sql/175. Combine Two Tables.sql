# Write your MySQL query statement below
-- select firstName, lastName, city, state  
-- from Person 
-- LEFT JOIN Address on Person.personId=Address.personId
select p.firstName, p.lastName,a.city,a.state
from Person p
left join Address a using(personId)

# Write your MySQL query statement below
SELECT user_id,concat(upper(Left(name,1)),lower(right(name,length(name)-1))) as name
FROM users
Order by user_id;
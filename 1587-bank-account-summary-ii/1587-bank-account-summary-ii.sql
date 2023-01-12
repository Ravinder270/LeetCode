# Write your MySQL query statement below
Select a.name, Sum(amount) as balance From Users a 
Join Transactions b on a.account=b.account
Group By a.name
Having Sum(amount)>10000
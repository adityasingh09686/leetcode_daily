select num as id, count(*) as num 
from (
    select requester_id as num from RequestAccepted 
    union all 
    select accepter_id as num from RequestAccepted
) as all_friends
group by id
order by num desc 
limit 1;
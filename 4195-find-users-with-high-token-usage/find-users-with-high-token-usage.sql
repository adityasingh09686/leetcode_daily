-- Write your PostgreSQL query statement below
select user_id , count(user_id) as prompt_count, round(AVG(tokens),2) as avg_tokens from prompts
group by user_id
having COUNT(prompt) >= 3
    AND MAX(tokens) > AVG(tokens)
ORDER BY avg_tokens DESC, user_id ASC;

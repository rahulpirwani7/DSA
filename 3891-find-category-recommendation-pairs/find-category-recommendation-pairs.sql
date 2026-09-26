# Write your MySQL query statement below
SELECT 
    pi.category AS category1,
    pi1.category AS category2,
    COUNT(DISTINCT pp.user_id) AS customer_count
FROM ProductPurchases pp
JOIN ProductPurchases pp1 
    ON pp.user_id = pp1.user_id

JOIN ProductInfo pi 
    ON pp.product_id = pi.product_id
JOIN ProductInfo pi1 
    ON pp1.product_id = pi1.product_id

WHERE pi.category < pi1.category 
GROUP BY pi.category, pi1.category
HAVING COUNT(DISTINCT pp.user_id) >= 3
ORDER BY customer_count DESC, category1, category2
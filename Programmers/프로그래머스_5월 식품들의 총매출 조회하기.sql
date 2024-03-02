SELECT 
  p.product_id, 
  p.product_name, 
  sum(p.price * o.amount) as total_sales
FROM food_order o
JOIN food_product p on p.product_id = o.product_id
WHERE TO_CHAR(o.produce_date, 'yyyy-mm') = '2022-05'
GROUP BY p.product_id, p.product_name
ORDER BY TOTAL_SALES DESC, p.product_id asc
;

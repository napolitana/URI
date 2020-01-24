#PRIMEIRA OPÇÃO
SELECT tb1.name, tb1.customers_number FROM (SELECT name, customers_number FROM lawyers GROUP BY name, customers_number HAVING customers_number = (SELECT MAX(customers_number) FROM lawyers) ) AS tb1
UNION ALL
SELECT tb2.name, tb2.customers_number FROM (SELECT name, customers_number FROM lawyers GROUP BY name, customers_number HAVING customers_number = (SELECT MIN(customers_number) FROM lawyers) ) AS tb2
UNION ALL
SELECT 'Average', TRUNCATE(AVG(customers_number), 0) FROM lawyers; 

#SEGUNDA OPÇÃO
SELECT lawyers.name, lawyers.customers_number FROM lawyers, (SELECT MAX(customers_number) AS cust_max FROM lawyers) AS tbl1 WHERE lawyers.customers_number = tbl1.cust_max 
UNION ALL
SELECT lawyers.name, lawyers.customers_number FROM lawyers, (SELECT MIN(customers_number) AS cust_min FROM lawyers) AS tbl2 WHERE lawyers.customers_number = tbl2.cust_min 
UNION ALL
SELECT 'Average', TRUNCATE(AVG(customers_number), 0) FROM lawyers 

#TERCEIRA OPÇÃO (faltando ordenar)
(SELECT lawyers.name, lawyers.customers_number
FROM lawyers,  (SELECT MAX(customers_number) AS cust_max, MIN(customers_number) AS cust_min FROM lawyers) AS tbl
WHERE lawyers.customers_number = tbl.cust_max OR lawyers.customers_number = tbl.cust_min GROUP BY lawyers.name ORDER BY lawyers.customers_number) 
UNION ALL
SELECT 'Average' AS name, TRUNCATE(AVG(tbl_avg.customers_number), 0) AS customers_number FROM lawyers AS tbl_avg;







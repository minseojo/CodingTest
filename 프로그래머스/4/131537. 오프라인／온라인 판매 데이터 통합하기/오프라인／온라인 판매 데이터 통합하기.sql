SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') SALES_DATE, PRODUCT_ID, USER_ID, SALES_AMOUNT
FROM ONLINE_SALE
WHERE YEAR(SALES_DATE) = 2022 AND MONTH(SALES_DATE) = 3

UNION ALL

SELECT DATE_FORMAT(SALES_DATE, '%Y-%m-%d') SALES_DATE, PRODUCT_ID, NULL, SALES_AMOUNT
FROM OFFLINE_SALE
WHERE YEAR(SALES_DATE) = 2022 AND MONTH(SALES_DATE) = 3

ORDER BY SALES_DATE, PRODUCT_ID, USER_ID
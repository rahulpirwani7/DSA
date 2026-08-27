SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance I1
WHERE tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
)
AND NOT EXISTS (
    SELECT 1
    FROM Insurance I2
    WHERE I1.pid != I2.pid
      AND I1.lat = I2.lat
      AND I1.lon = I2.lon
);
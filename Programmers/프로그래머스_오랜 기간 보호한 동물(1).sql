-- https://programmers.co.kr/learn/courses/30/lessons/59044
SELECT *
    FROM (
        SELECT A.NAME, A.DATETIME
            FROM ANIMAL_INS A
            LEFT JOIN ANIMAL_OUTS B
            ON A.ANIMAL_ID = B.ANIMAL_ID
            WHERE B.ANIMAL_ID IS NOT NULL
            ORDER BY DATETIME ASC
    )
    WHERE ROWNUM <= 3
CREATE OR REPLACE TYPE t_fvrt_food IS VARRAY(10) OF NUMBER(2);

CREATE TABLE TEST_AUTO_INCREMENT
(
  ID            NUMBER(12)                      NOT NULL,
  DESCRIPTON    VARCHAR2(40 BYTE),
  TEST_ARRAY    T_FVRT_FOOD,
  TEST_FLOAT    NUMBER,
  TEST_INTEGER  NUMBER(10),
  TEST_DECIMAL  NUMBER(12,2),
PRIMARY KEY (id)
)

--
-- Generated by VASY
--
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY ao22_x2 IS
PORT(
  i0	: IN STD_LOGIC;
  i1	: IN STD_LOGIC;
  i2	: IN STD_LOGIC;
  q	: OUT STD_LOGIC
);
END ao22_x2;

ARCHITECTURE RTL OF ao22_x2 IS
BEGIN
  q <= ((i0 OR i1) AND i2);
END RTL;

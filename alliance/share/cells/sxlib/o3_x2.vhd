
--
-- Generated by VASY
--
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY o3_x2 IS
PORT(
  i0	: IN STD_LOGIC;
  i1	: IN STD_LOGIC;
  i2	: IN STD_LOGIC;
  q	: OUT STD_LOGIC
);
END o3_x2;

ARCHITECTURE RTL OF o3_x2 IS
BEGIN
  q <= ((i0 OR i1) OR i2);
END RTL;

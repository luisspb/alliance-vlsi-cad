
in       clk B;;
in       rst B;;
in       stb B;;
in       A (7 downto 0) X;;
in       B (7 downto 0) X;;
out      result (15 downto 0) X;;
out      done B;

register u3.state(0 to 2) X;;
register u1.outsint(7 downto 0) X;;

begin

-- PATTERN DESCRIPTION :

 : 0 1 0 00 00 ?**** ?* ?* ?**;
 : 1 1 0 00 00 ?**** ?* ?* ?**;
 : 0 1 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 1 00 00 ?**** ?* ?* ?**;
 : 1 0 1 00 00 ?**** ?* ?* ?**;
 : 0 0 1 00 00 ?**** ?* ?* ?**;
 : 0 0 0 02 03 ?**** ?* ?* ?**;
 : 1 0 0 02 03 ?**** ?* ?* ?**;
 : 0 0 0 02 03 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;
 : 1 0 0 00 00 ?**** ?* ?* ?**;
 : 0 0 0 00 00 ?**** ?* ?* ?**;

end;

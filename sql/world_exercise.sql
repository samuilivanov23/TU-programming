/* Самоподготовка ТУ 1-3 */

/* JOINs */

/* 1 */
select co.Name, ci.Name, ci.Population from country as co join city as ci on co.Code=ci.CountryCode where co.Code='BGR';

/* 2 */
select co.Name, ci.Name from country as co join city as ci on co.Capital=ci.id order by co.Name;

/* 3 */
select co.Name as Country, ci.Name as Capital from country as co join city as ci on co.Capital=ci.id order by co.Name;

/* 4 */
select co.Name as Country, ci.Name as Capital from country as co join city as ci on co.Capital=ci.id where co.Continent='Europe' order by co.Name;

/* 5 */
select co.Name as Country, ci.Name as Capital, co.Population as CountryPoplation, ci.Population as CapitalPopulation from country as co join city as ci on co.Capital=ci.id where co.Name='Malta';

/* 6 */
select co.Name as CountryName, cl.Language as Language from country as co join countrylanguage as cl on co.Code=cl.CountryCode where co.Name='Australia';

/* 7 */
select distinct cl.Language as Language, co.Region as Region from country as co join countrylanguage as cl on co.Code=cl.CountryCode where co.Region='Caribbean';

/* GROUP BY */

/* 1 */
select co.Continent as Continent, SUM(co.SurfaceArea) as SurfaceArea from country as co group by co.Continent;

/* 2 */
select co.Continent, co.Name, co.population from country as co where co.population in (select MAX(co.Population) as CountryPopulation from country as co join city as ci on co.Code=ci.CountryCode group by co.Continent);

/* 3 */
select co.Region as Region, AVG(co.LifeExpectancy) as LifeExpectancy from (select * from country where Continent='Europe') as co group by co.Region;

/* 4 */
select co.Continent, COUNT(co.Name) as 'Country Count' from country as co group by co.Continent;

/* 5 */
select co.Continent, co.Name, co.population from country as co where co.population in (select MIN(co.Population) as CountryPopulation from country as co join city as ci on co.Code=ci.CountryCode group by co.Continent);

/* HAVING */

/* 1 */
select co.Continent, SUM(co.Population) from country as co group by continent having SUM(co.Population)>700000000;

/* 2 */
select co.Continent, AVG(co.LifeExpectancy) from country as co group by continent having AVG(co.LifeExpectancy)>75;

/* 3 */
select cl.language, COUNT(co.Name) from country as co join countrylanguage as cl on co.Code=cl.CountryCode group by cl.language having COUNT(co.Name)>20;

/* 4 Не съм сигурен логически дали се изисква точно това??? */
select co.GovernmentForm from country as co group by co.GovernmentForm having SUM(co.Population)>100000000;

/* 5 */
select co.Name, COUNT(cl.language) from country as co join countrylanguage as cl on co.Code=cl.CountryCode group by co.Name HAVING COUNT(cl.language)>10;

/* 6 */
select co.Name, COUNT(cl.language) from country as co join (select * from countrylanguage where IsOfficial=TRUE) as cl on co.Code=cl.CountryCode group by co.Name HAVING COUNT(cl.language)>3;



/* NESTED QUERIES */

/* 1 */
select co.Name, co.SurfaceArea from country as co where co.SurfaceArea=(select MAX(co.SurfaceArea) from country as co);

/* 2 */
select co.Name, co.SurfaceArea from country as co where co.SurfaceArea=(select MIN(co.SurfaceArea) from country as co);

/* 3 Possible Optimization*/
select co.Name, co.Population from country as co where co.Continent='South America' and co.Population=(select MAX(co.Population) from country as co where co.Continent='South America');

/* 4 Possible Optimization */
select cl.language, cl.Percentage from (select * from countrylanguage as cl where cl.CountryCode='ARG') as cl where cl.Percentage=(select MAX(cl.Percentage) from countrylanguage as cl where cl.CountryCode='ARG');

/* 5 */
select co.Name, co.LifeExpectancy from country as co where co.LifeExpectancy>(select AVG(co.LifeExpectancy) from country as co);

/* 6 cl.Percentage (optional col for sanity check)*/
select co.Name, cl.language, cl.Percentage from country as co join (select cl.CountryCode, cl.language, cl.Percentage from countrylanguage as cl where cl.Percentage in (select MAX(cl.Percentage) from countrylanguage as cl group by cl.CountryCode)) as cl on co.Code=c
l.CountryCode;

begin transaction; update country set Population=(Population-200) where Name='Ukraine'; update country set Population=(Population+200) where Name='Poland'; commit;

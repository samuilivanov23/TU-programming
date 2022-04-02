select co.Name, ci.Name, ci.Population from country as co join city as ci on co.Code=ci.CountryCode where co.Code='BGR';

select co.Name, ci.Name from country as co join city as ci on co.Capital=ci.id;

select co.Name as Country, ci.Name as Capital from country as co join city as ci on co.Capital=ci.id;

select co.Name as Country, ci.Name as Capital from country as co join city as ci on co.Capital=ci.id where co.Continent='Europe';

select co.Name as Country, ci.Name as Capital, (select SUM(ci.Population) from country as co join city as ci on co.Code=ci.CountryCode where co.Name='Malta') as CountryPoplation, ci.Population as CapitalPopulation from country as co join city as ci on co.Capital=ci.id where co.Name='Malta';

select co.Name as CountryName, cl.Language as Language from country as co join countrylanguage as cl on co.Code=cl.CountryCode where co.Name='Australia';

select cl.Language as Language, co.Region as Region from country as co join countrylanguage as cl on co.Code=cl.CountryCode where co.Region='Caribbean';

select co.Continent as Continent, SUM(co.SurfaceArea) as SurfaceArea from country as co group by co.Continent;

select co.Continent as Continent, MAX(co.Population) as CountryPopulation from country as co join city as ci on co.Code=ci.CountryCode group by co.Continent;

select co.Region as Region, AVG(co.LifeExpectancy) as LifeExpectancy from (select * from country where Continent='Europe') as co group by co.Region;

begin transaction; update country set Population=(Population-200) where Name='Ukraine'; update country set Population=(Population+200) where Name='Poland'; commit;

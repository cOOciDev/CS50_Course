-- Keep a log of any SQL queries you execute as you solve the mystery.

-- queri for see crime scene TABLE
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street" AND description like "%cs50%";


-- queri for find crime scene id == 295
SELECT id FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street" AND description like "%cs50%";


-- queri for Read description about crime scene
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%thief%";








-- queri for find some cars who left the bakery   (discrition id 161)
SELECT * FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND minute > 15 AND minute < 25 AND activity="exit";

SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND minute > 15 AND minute < 25 AND activity="exit");





-- query for find a list about people who take mony from ATM   (description id 162)
SELECT * FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND atm_location="Leggett Street" AND transaction_type="withdraw";

-- find bank accounts
SELECT * FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND atm_location="Leggett Street" AND transaction_type="withdraw");

-- find peoples information
SELECT * FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND atm_location="Leggett Street" AND transaction_type="withdraw"));






-- query for find a list about earliest airplans ticket on tomarow   (description id 163)
SELECT * FROM flights WHERE year=2021 AND month=7 And day=29 AND hour=8;

-- find flight destination
SELECT * FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE year=2021 AND month=7 And day=29 AND hour=8);
--   => ESCAPE TO New York City




-- find call
SELECT * FROM phone_calls WHERE year=2021 AND month=7 And day=28 AND duration < 60;

-- find callers on time frame
SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year=2021 AND month=7 And day=28 AND duration < 60);


-- find receiver on time frame
SELECT * FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year=2021 AND month=7 And day=28 AND duration < 60);








-- find airport
SELECT * FROM airports WHERE id IN (SELECT origin_airport_id FROM flights WHERE year=2021 AND month=7 And day=29 AND hour=8);
--find travellers pasport and information
SELECT * FROM passengers WHERE flight_id IN (SELECT id FROM airports WHERE id IN(SELECT origin_airport_id FROM flights WHERE year=2021 AND month=7 And day=29 AND hour=8));

select * from people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM airports WHERE id IN(SELECT origin_airport_id FROM flights WHERE year=2021 AND month=7 And day=29 AND hour=8)));











-- find THE THEiF
SELECT * FROM people WHERE license_plate IN
(SELECT license_plate FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND atm_location="Leggett Street" AND transaction_type="withdraw")) AND license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE year=2021 AND month=7 AND day=28 AND hour=10 AND minute > 15 AND minute < 25 AND activity="exit")AND phone_number IN
(SELECT caller FROM phone_calls WHERE year=2021 AND month=7 And day=28 AND duration < 60);

-- Bruce







-- find The ACCOMPLICE
SELECT * FROM people WHERE phone_number IN
(SELECT receiver FROM phone_calls WHERE year=2021 AND month=7 And day=28 AND duration < 60 AND caller ="(367) 555-5533");


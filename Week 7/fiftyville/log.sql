-- First i ran this command to know what the theif stole
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';
-- this was the answer : ---------------------------------------------------------------+
| Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
| Littering took place at 16:36. No known witnesses.


-- i then ran this query to get more information from the witnesses
SELECT name, transcript
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28;
--If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
--Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.


SELECT license_plate FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND hour = 10 AND minute >=15  ;

-- got nothing interesting from this query

SELECT name
  FROM people
 WHERE name = 'Eugene';

 -- only one man named eugene, interesting


 -- Eugene gave clues- Thief was withdrawing money from the ATM on Leggett Street.
SELECT account_number, amount
  FROM atm_transactions
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';

   SELECT name, atm_transactions.amount
  FROM people
  JOIN bank_accounts
    ON people.id = bank_accounts.person_id
  JOIN atm_transactions
    ON bank_accounts.account_number = atm_transactions.account_number
 WHERE atm_transactions.year = 2021
   AND atm_transactions.month = 7
   AND atm_transactions.day = 28
   AND atm_transactions.atm_location = 'Leggett Street'
   AND atm_transactions.transaction_type = 'withdraw';

   +---------+--------+
|  name   | amount |
+---------+--------+
| Bruce   | 50     |
| Diana   | 35     |
| Brooke  | 80     |
| Kenny   | 20     |
| Iman    | 20     |
| Luca    | 48     |
| Taylor  | 60     |
| Benista | 30     |
+---------+--------+

-- right now just getting some data and not very interesting to say so

-- checking phone calles the minute call raymond tallked about where he talked about a flight

SELECT flights.id, full_name, city, flights.hour, flights.minute
  FROM airports
  JOIN flights
    ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id =
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
   AND flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
 ORDER BY flights.hour, flights.minute;

 -- 36 | LaGuardia Airport                   | New York City | 8    | 20

 -- check names on id flight

 SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
  FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON passengers.flight_id = flights.id
 WHERE flights.year = 2021
   AND flights.month = 7
   AND flights.day = 29
   AND flights.hour = 8
   AND flights.minute = 20
 ORDER BY passengers.passport_number;

 -- found bruce that goffy , i am going to assume that he is my primary susbect from now on as he is the only one found within the atm transactions and had an early flight

 -- Checking the phone call records to find the person who bought the tickets.
-- Firstly, checking the possible names of the caller, and putting these names in the 'Suspect List'. Ordering them according to the durations of the calls.
SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
 ORDER BY phone_calls.duration;

-- weirdly alot people from the flight made some calls also which is quite disturbing to say

SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
  FROM people
  JOIN bakery_security_logs
    ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021
   AND bakery_security_logs.month = 7
   AND bakery_security_logs.day = 28
   AND bakery_security_logs.activity = 'exit'
   AND bakery_security_logs.hour = 10
   AND bakery_security_logs.minute >= 15
   AND bakery_security_logs.minute <= 25
 ORDER BY bakery_security_logs.minute;

 +---------+------+--------+
|  name   | hour | minute |
+---------+------+--------+
| Vanessa | 10   | 16     |
| Bruce   | 10   | 18     |
| Barry   | 10   | 18     |
| Luca    | 10   | 19     |
| Sofia   | 10   | 20     |
| Iman    | 10   | 21     |
| Diana   | 10   | 23     |
| Kelsey  | 10   | 23     |
+---------+------+--------+

-- bruce was seen getting out of the bakery at 10:18 it also amounts to the minutes the theif had for the call 

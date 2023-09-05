import csv
import sys

def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # Read database file into a list of dictionaries
    database = sys.argv[1]
    with open(database, 'r') as file:
        reader_1 = csv.DictReader(file)
        database_list = list(reader_1)

    # Read DNA sequence file into a string
    sequence = sys.argv[2]
    with open(sequence, 'r') as file_2:
        reader_2 = file_2.read()

    # Define the STRs to search for
    strs = reader_1.fieldnames[1:]

    # Find longest match of each STR in DNA sequence
    matches = {}
    for str in strs:
        matches[str] = longest_match(reader_2, str)

    # Check database for matching profiles using the matches dictionary
    for profile in database_list:
        if all(int(profile[str]) == matches[str] for str in strs):
            print(profile["name"])
            return

    # If no match is found
    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

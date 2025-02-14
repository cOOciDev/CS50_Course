import csv
from sys import argv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Usage : Python dna.py data.csv seguence.text")

    # TODO: Read database file into a variable
    Data_base_file = open("./" + argv[1])
    DataBase_Reader = csv.DictReader(Data_base_file)

    # TODO: Read DNA sequence file into a variable
    Dna_file = open("./" + argv[2])
    Strs = DataBase_Reader.fieldnames[1:]
    Dna = Dna_file.read()
    Dna_file.close()

    # TODO: Find longest match of each STR in DNA sequence
    Dna_fingerprint = {}
    for str in Strs:
        Dna_fingerprint[str] = longest_match(Dna, str)

    # TODO: Check database for matching profiles
    for row in DataBase_Reader:
        if Match(Strs, Dna_fingerprint, row):
            print(f"{row['name']}")
            Data_base_file.close()
            return

    print("No match")
    Data_base_file.close()

    return


def Match(strs, dna_fingerprint, row):
    for str in strs:
        if dna_fingerprint[str] != int(row[str]):
            return False
    return True


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

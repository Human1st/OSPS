import sys
import os

path = os.path.dirname(os.path.realpath(__file__))
provider_file = open(path + "/french_provider.csv", "r")
ranges_file = open(path + "/french_ranges.csv", "r")

def main():
    french(sys.argv[1])

def french(number: str):
    for phone_range in ranges_file:
        try:
            if is_inrange(number, phone_range.split(",")[1], phone_range.split(",")[2]):
                print("Phone range founded:", phone_range, end="")
                print("Provider:", find_provider_name(phone_range.split(",")[3]), end="")
        except:
            pass

def find_provider_name(code: str):
    for provider in provider_file:
        if provider.split(",")[0] == code:
            return provider.split(",")[1]
    return "PROVIDER_NOT_FOUND"

def is_inrange(phone, rangesta, rangesto):
    for digit in range(len(phone)):
        if int(phone[digit]) < int(rangesta[digit]) or int(phone[digit]) > int(rangesto[digit]):
            return 0
    return 1
if __name__ == "__main__":
    main()

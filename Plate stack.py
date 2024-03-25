plate_stack = []

def add_plate():
    size = int(input("Enter a plate size: "))
    if size <= 0:
        print("Error: Plate size must be a positive integer.")
    elif not plate_stack or size <= plate_stack[-1]:
        plate_stack.append(size)
        print("Success: Plate added to the stack.")
    else:
        print(f"Error: Cannot place a plate of size {size} on top of another plate of size {plate_stack[-1]}.")

def print_plates():
    if plate_stack:
        print("Print plates:")
        for plate in reversed(plate_stack):
            print(plate)
    else:
        print("There are no stacked plates.")

def remove_plates():
    num = int(input("How many plates to remove?: "))
    if num <= 0:
        print("Error: Number of plates to remove must be a positive integer.")
    elif len(plate_stack) < num:
        print(f"Error: Cannot remove {num} plates. There are only {len(plate_stack)} plates in the stack.")
    else:
        removed_plates = plate_stack[-num:]
        del plate_stack[-num:]
        print("Success: Plates removed from the stack.")
        print("Removed Plates:", removed_plates)

def main():
    while True:
        print("\nMenu:")
        print("====")
        print("0. [Exit]")
        print("1. Add a plate")
        print("2. Print plates")
        print("3. Remove plates")
        choice = input("Select [0-3]: ")
        if choice == '0':
            print("Goodbye!")
            break
        elif choice == '1':
            add_plate()
        elif choice == '2':
            print_plates()
        elif choice == '3':
            remove_plates()
        else:
            print("Invalid choice. Please select again.")

if __name__ == "__main__":
    main()

def search_duplicate(files: list[str], hash: callable) -> list[str]:
    duplicates = []
    work_hash = []
    for file in files:
        with open(file, 'r') as f:
            body = f.read()
            hashed_body = hash(body)
            if hashed_body in work_hash:
                duplicates.append(file)
            else:
                work_hash.append(hashed_body)
    return duplicates
def tlv_parser(tlv_data):
    items = []
    i = 0
    while i < len(tlv_data):
        tag = tlv_data[i]
        if i + 1 >= len(tlv_data):
            break  # truncated: no length
        length = tlv_data[i + 1]
        start = i + 2
        end = start + length
        if end > len(tlv_data):
            break  # truncated: incomplete value
        value = tlv_data[start:end]

        print(f"Tag: {tag}, Length: {length}, Value: {value}")
        items.append({"tag": tag, "length": length, "value": value})

        i = end
    return items


if __name__ == '__main__':
    tlv_data = [0x00, 0x05, 0x41, 0x50, 0x50, 0x4C, 0x45, 0x01, 0x01, 0x82]
    parsed_data = tlv_parser(tlv_data)
    print(parsed_data)
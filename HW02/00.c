uint64_t findMaxBlock(list *head) {
    if (head == NULL) {
        return 0; // Если список пустой, возвращаем NULL (0)
    }

    uint64_t maxAddress = head->address;
    size_t maxSize = head->size;

    list *current = head->next;

    while (current != NULL) {
        if (current->size > maxSize) {
            maxSize = current->size;
            maxAddress = current->address;
        }
        current = current->next;
    }

    return maxAddress;
}

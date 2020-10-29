class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        list_stack = []
        string_operation = "+-/*"
        return_value_of_expression = 0
        for i in range(0,len(tokens)):
            if tokens[i] not in string_operation:
                list_stack.append(tokens[i])
            else:
                first_element = int(list_stack[-1])
                del list_stack[-1]
                second_element = int(list_stack[-1])
                del list_stack[-1]
                if tokens[i] == "+":
                    list_stack.append(first_element+second_element)
                if tokens[i] == "-":
                    list_stack.append(second_element-first_element)
                if tokens[i] == "/":
                    div_value = int(float(second_element)/first_element) 
                    list_stack.append(div_value)
                if tokens[i] == "*":
                    list_stack.append(first_element * second_element)
        
        return_value_of_expression = list_stack[-1]
        return return_value_of_expression

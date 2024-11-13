import re

def clean_template(input_file_path, output_file_path):
    with open(input_file_path, 'r') as file:
        content = file.read()


    # Extract #include directives to sort and remove duplicates
    includes = sorted(set(re.findall(r'#include <[^>]+>', content)))

    # Remove the specific block starting with <% and ending with %>
    specific_block_pattern = r'<%[\s\S]*?%>'
    content = re.sub(specific_block_pattern, '', content)

    # Remove oj-tools specific multiline blocks and placeholders
    content = re.sub(r'<%![\s\S]*?%>', '', content)  # Removes <%! ... %> blocks
    content = re.sub(r'\$\{[^}]+\}', '', content)  # Removes ${...} placeholders
    # content = re.sub(r'//.*\n', '\n', content)  # Removes single line comments
    # content = re.sub(r'/\*[^*]*\*+(?:[^/*][^*]*\*+)*/', '', content, flags=re.DOTALL)  # Removes block comments
    # content = re.sub(r'\n\s*\n', '\n\n', content)  # Removes extra empty lines

    # Remove conditional blocks including % if topcoder.is_topcoder(data): ... % else: ... % endif
    content = re.sub(r'% if topcoder\.is_topcoder\(data\):[\s\S]*?% else:', '', content)
    content = re.sub(r'% endif', '', content)

    # Remove existing #include lines from the content
    content = re.sub(r'#include <[^>]+>\n', '', content)


    # Ensure the solve() function has a void return type
    solve_pattern = r'\b(?<!\w)(solve\(\))'
    if re.search(solve_pattern, content):
        content = re.sub(solve_pattern, 'void \\1', content)
    # Remove leading whitespace from lines containing 'void solve()'
    content = re.sub(r'^\s*(void\s+solve\(\))', '\\1', content, flags=re.MULTILINE)
    # Remove lines starting with 'auto  = ();'
    content = re.sub(r'^\s*auto\s+=\s*\(\);\s*\n', '', content, flags=re.MULTILINE)

    # Prepend sorted #include directives to the rest of the content
    final_content = '\n'.join(includes) + '\n\n' + content
    final_content = re.sub(r'.*bits/stdc.*\n', '', final_content)

    line1 = "template <typename Func, typename Seq>"
    line2 = "auto transform_to_vector(const Func &f, const Seq &s) {"
    pattern = "template <typename Func, typename Seq>\n" \
              "auto transform_to_vector(const Func &f, const Seq &s) {\n"

    target_line = "using mint = modint998244353;"
    if target_line in final_content and not f"//{target_line}" in final_content:
        # Replace the first occurrence of the target line with its commented version
        final_content = final_content.replace(target_line, f"//{target_line}", 1)

    start_index = final_content.find(pattern)
    print(start_index)
    # If the pattern is found
    if start_index != -1:
        # Find the end of the 200 lines after the pattern
        end_index = start_index
        for _ in range(687):  # Including the two lines of the pattern
            end_index = final_content.find('\n', end_index + 1)
            if end_index == -1:  # If the end of file is reached
                break
        
        # Delete the pattern and the next 200 lines
        final_content = final_content[:start_index] + final_content[end_index+1:]

    # Write the final cleaned content to the output file
    with open(output_file_path, 'w') as file:
        file.write(final_content)


# Adjust the file paths as needed
input_file_path = '/Users/samir/.pyenv/versions/3.9.10/lib/python3.9/site-packages/onlinejudge_template_resources/template/main.cpp'
output_file_path = '/Users/samir/.pyenv/versions/3.9.10/lib/python3.9/site-packages/onlinejudge_template_resources/template/cleaned.cpp'

clean_template(input_file_path, output_file_path)

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

    # Write the final cleaned content to the output file
    with open(output_file_path, 'w') as file:
        file.write(final_content)


# Adjust the file paths as needed
input_file_path = '/Users/samir/.pyenv/versions/3.9.10/lib/python3.9/site-packages/onlinejudge_template_resources/template/main.cpp'
output_file_path = '/Users/samir/.pyenv/versions/3.9.10/lib/python3.9/site-packages/onlinejudge_template_resources/template/cleaned.cpp'

clean_template(input_file_path, output_file_path)

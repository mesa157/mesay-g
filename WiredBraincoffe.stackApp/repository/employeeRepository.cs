

using System.Collections.Generic;

using WiredBraincoffe.stackApp.intity;

namespace WiredBraincoffe.stackApp.repository
{
    public class EmployeeRepository
    {
        private readonly List<Employee> _employees = new();

        public void Add(Employee employee)
        {
            _employees.Add(employee);

        }
        public void save()
        {

        }
    }
}

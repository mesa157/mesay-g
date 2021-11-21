using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace WiredBraincoffe.stackApp
{
    public class program
    {
        static void main(string[] args)
        {
            var employeeRepository = new EmployeeRepository();
            employeeRepository.Add(FirstName = "julia");
        }
        class Employee
        {
            public int ID { get; set; }
            public string FristName { get; set; }

            public string String() => $"ID: {ID}  , FristName {FristName}";

        }
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
}
